using System;
using System.Net.Http;
using System.Threading.Tasks;

using Microsoft.AspNetCore.Components;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;
using Microsoft.Extensions.DependencyInjection;

namespace Stryxus.Lib.AspNet.WebAssembly
{
    public static class ASPHostBuilder
    {
        public static async Task RunClientHost<T>(string[] args) where T : IComponent => await CreateClientHost<T>(args).Build().RunAsync();
        public static WebAssemblyHostBuilder CreateClientHost<T>(string[] args) where T : IComponent
        {
            WebAssemblyHostBuilder builder = WebAssemblyHostBuilder.CreateDefault(args);
            builder.RootComponents.Add<T>("#app");
            builder.Services.AddScoped(sp => new HttpClient { BaseAddress = new Uri(builder.HostEnvironment.BaseAddress) });
            return builder;
        }
    }
}