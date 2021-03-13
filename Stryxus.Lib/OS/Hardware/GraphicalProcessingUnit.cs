using System;

using Stryxus.Lib.OS.Abstractions;

namespace Stryxus.Lib.OS.Hardware
{
    public class GraphicalProcessingUnit
    {
        public DirectX DX { get; private set; }
        public Vulkan Vulk { get; private set; }

        public GraphicalProcessingUnit()
        {

        }
    }
}
