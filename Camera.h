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


camerapos get_camera()
{
	

	camerapos cam{};

	auto location_pointer = Kernel.Read<uintptr_t>(hpointer.UWorld + 0x128);
	auto rotation_pointer = Kernel.Read<uintptr_t>(hpointer.UWorld + 0x138);

	double pitch = Kernel.Read<double>(rotation_pointer);
	double yaw = Kernel.Read<double>(rotation_pointer + 0x20);
	double roll = Kernel.Read<double>(rotation_pointer + 0x1d0);

	cam.rotation.x = asin(roll) * (180.0 / M_PI);
	cam.rotation.y = ((atan2(pitch * -1, yaw) * (180.0 / M_PI)) * -1) * -1;
	cam.location = Kernel.Read<fvector>(location_pointer);
	cam.fov = Kernel.Read<float>(hpointer.LocalPlayer + 0x4ac);

	return cam;
}
// Fud camera
