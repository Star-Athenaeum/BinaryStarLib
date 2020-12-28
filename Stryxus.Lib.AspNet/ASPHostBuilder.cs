using System;
using System.IO.Compression;
using System.Linq;
using System.Threading.Tasks;

using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Components;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.ResponseCompression;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;

namespace Stryxus.Lib.AspNet
{
    public static class ASPHostBuilder
    {
        public enum ServerHostType
        {
            Static,
            PreRender,
            WebAssembly,
            WebAssemblyCommunable
        }

        public static async Task RunServerHost(ServerHostType type) => await CreateServerHost(type).Build().RunAsync();
        public static IHostBuilder CreateServerHost(ServerHostType type) => Host.CreateDefaultBuilder().ConfigureWebHostDefaults((webBuilder) =>
        {
            webBuilder.ConfigureServices((services) =>
            {
                services.AddResponseCompression(options =>
                {
                    options.Providers.Add<BrotliCompressionProvider>();
                    options.Providers.Add<GzipCompressionProvider>();
                    options.MimeTypes = ResponseCompressionDefaults.MimeTypes.Concat(new[] { "image/svg+xml" });
                });
                services.AddRazorPages();
                services.Configure<BrotliCompressionProviderOptions>(options => options.Level = (CompressionLevel)4);
                services.Configure<RazorPagesOptions>(options => options.RootDirectory = "/Pages");
                if (type == ServerHostType.WebAssembly || type == ServerHostType.WebAssemblyCommunable) services.AddServerSideBlazor();
            });

            webBuilder.Configure((app) =>
            {
                ASPServices.Provider = app.ApplicationServices.GetRequiredService<IServiceScopeFactory>().CreateScope().ServiceProvider;
                ASPServices.IsDevelopmentMode = app.ApplicationServices.GetRequiredService<IWebHostEnvironment>().IsDevelopment();

                if (ASPServices.IsDevelopmentMode)
                {
                    app.UseDeveloperExceptionPage();
                    if (type == ServerHostType.WebAssembly || type == ServerHostType.WebAssemblyCommunable) app.UseWebAssemblyDebugging();
                }
                else
                {
                    app.UseExceptionHandler("/Error");
                    app.UseHsts();
                }

                app.UseResponseCompression();
                app.UseHttpsRedirection();
                if (type == ServerHostType.WebAssembly || type == ServerHostType.WebAssemblyCommunable) app.UseBlazorFrameworkFiles();
                app.UseStaticFiles();
                app.UseRouting();
                app.UseEndpoints(endpoints =>
                {
                    if (type == ServerHostType.Static)
                    {
                        endpoints.MapFallbackToPage("/_Host");
                    }
                    else if (type == ServerHostType.PreRender)
                    {
                        endpoints.MapBlazorHub();
                        endpoints.MapFallbackToPage("/_Host");
                    }
                    else if (type == ServerHostType.WebAssembly || type == ServerHostType.WebAssemblyCommunable)
                    {
                        endpoints.MapRazorPages();
                        endpoints.MapControllers();
                        endpoints.MapFallbackToFile("index.html");
                    }
                });
            });
        });

        public static async Task RunClientHost<T>() where T : IComponent => await CreateClientHost<T>().Build().RunAsync();
        public static WebAssemblyHostBuilder CreateClientHost<T>() where T : IComponent
        {
            WebAssemblyHostBuilder builder = WebAssemblyHostBuilder.CreateDefault();
            builder.RootComponents.Add<T>("#app");
            return builder;
        }
    }
}