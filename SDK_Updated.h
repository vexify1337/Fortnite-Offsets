namespace offsets {
 	inline static uintptr_t LastRenderTime = 0x30C;
inline static uintptr_t WorldSeconds = 0x150;

}

namespace fnsdk {
bool VisiCheck(uintptr_t cached_mesh)
	{
		auto Mili = Kernel.Read<double>(cached::gworld + offsets::WorldSeconds);
		auto LastRenderTime = Kernel.Read<float>(cached_mesh + offsets::LastRenderTime); // 0x30C
		return Mili - LastRenderTime <= 0.06f;
	}
}

// ill add more cheat functions like name esp, weapon update to this soon
