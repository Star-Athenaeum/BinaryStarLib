using System;

using BSL.OS.Abstractions;

namespace BSL.OS.Hardware
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
