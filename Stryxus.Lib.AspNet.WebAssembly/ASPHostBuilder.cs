using System;
using System.Threading.Tasks;

using Microsoft.AspNetCore.Components;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;

namespace Stryxus.Lib.AspNet.WebAssembly
{
    public static class ASPHostBuilder
    {
        public static async Task RunClientHost<T>(string[] args) where T : IComponent => await CreateClientHost<T>(args).Build().RunAsync();
        public static WebAssemblyHostBuilder CreateClientHost<T>(string[] args) where T : IComponent
        {
            WebAssemblyHostBuilder builder = WebAssemblyHostBuilder.CreateDefault(args);
            builder.RootComponents.Add<T>("app");
            return builder;
        }
    }
}