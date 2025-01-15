_SCamera get_view_point()
{
	_SCamera view_point{};
	uintptr_t loc = Kernel.Read<uintptr_t>(cached::gworld + 0x128); 
	uintptr_t rott = Kernel.Read<uintptr_t>(cached::gworld + 0x138); 
	FNRot fnrot{};
	fnrot.a = Kernel.Read<double>(rott);
	fnrot.b = Kernel.Read<double>(rott + 0x20);
	fnrot.c = Kernel.Read<double>(rott + 0x1D0);
	view_point.location = Kernel.Read<Vector3>(loc);
	view_point.rotation.x = asin(fnrot.c) * (180.0 / M_PI);
	view_point.rotation.y = ((atan2(fnrot.a * -1, fnrot.b) * (180.0 / M_PI)) * -1) * -1;
	view_point.fov = Kernel.Read<float>(cached::player_controller + 0x3AC) * 90.0f;
	return view_point;
}



// Fud camera
