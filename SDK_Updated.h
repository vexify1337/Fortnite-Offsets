namespace offsets {
 	inline static uintptr_t LastRenderTime = 0x30C;
inline static uintptr_t WorldSeconds = 0x150;

}

namespace fnsdk {
	bool VisiCheck(uintptr_t cached_mesh)
	{
		auto Mili = read<double>(cache::uworld + 0x160);
		auto LastRenderTime = read<float>(cached_mesh + 0x32C); // 0x30C
		return Mili - LastRenderTime <= 0.06f;
	}
}
// ill add more cheat functions like name esp, weapon update to this soon
