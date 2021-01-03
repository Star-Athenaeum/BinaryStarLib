using System;
using System.IO.Compression;
using System.Linq;
using System.Threading.Tasks;

using Microsoft.AspNetCore.Builder;
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

        public static async Task RunServerHost(IHostBuilder builder, ServerHostType type) => await CreateServerHost(builder, type).Build().RunAsync();
        public static IHostBuilder CreateServerHost(IHostBuilder builder, ServerHostType type) => builder.ConfigureWebHostDefaults((webBuilder) =>
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
                if (type == ServerHostType.PreRender)
                {
                    services.AddServerSideBlazor();
                    services.Configure<RazorPagesOptions>(options => options.RootDirectory = "/Pages");
                }
                else if (type == ServerHostType.Static) services.Configure<RazorPagesOptions>(options => options.RootDirectory = "/Pages");
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
                        endpoints.MapFallbackToFile("index.html");
                    }
                    else if (type == ServerHostType.PreRender)
                    {
                        endpoints.MapBlazorHub();
                        endpoints.MapFallbackToPage("/_Host");
                    }
                    else if (type == ServerHostType.WebAssembly || type == ServerHostType.WebAssemblyCommunable)
                    {
                        endpoints.MapFallbackToFile("index.html");
                    }
                });
            });
        });
    }
}