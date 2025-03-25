Camera get_view_point()
{
	//YOU MIGHT NEED TO UPDATE THE LOCATION AND ROTATION POINTER IN THE NEXT UPDATE SO CHECK IT OUT DONT FORGET!
	Camera view_point{};
	uintptr_t location_pointer = read<uintptr_t>(cache::uworld + 0x140); //
	uintptr_t rotation_pointer = read<uintptr_t>(cache::uworld + 0x150); //
	FNRot fnrot{};
	fnrot.a = read<double>(rotation_pointer);
	fnrot.b = read<double>(rotation_pointer + 0x20);
	fnrot.c = read<double>(rotation_pointer + 0x1D0);
	view_point.location = read<Vector3>(location_pointer);
	view_point.rotation.x = asin(fnrot.c) * (180.0 / M_PI);
	view_point.rotation.y = ((atan2(fnrot.a * -1, fnrot.b) * (180.0 / M_PI)) * -1) * -1;
	view_point.fov = read<float>(cache::player_controller + 0x3AC) * 90.0f;
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
