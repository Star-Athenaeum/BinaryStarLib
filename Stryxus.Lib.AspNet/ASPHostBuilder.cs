﻿using System;
using System.IO.Compression;
using System.Linq;
using System.Threading.Tasks;

using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Components;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;
using Microsoft.AspNetCore.Hosting;
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
                services.Configure<BrotliCompressionProviderOptions>(options => options.Level = (CompressionLevel)4);
                services.AddRazorPages();
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

        public static WebAssemblyHostBuilder CreateClientHost<T>() where T : IComponent
        {
            WebAssemblyHostBuilder builder = WebAssemblyHostBuilder.CreateDefault();
            builder.RootComponents.Add<T>("#app");
            return builder;
        }
    }
}