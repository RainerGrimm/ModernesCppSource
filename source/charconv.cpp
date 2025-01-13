double d = 123.456789;
std::format("{}", &d); // ERROR
std::format("{}", static_cast<void*>(&d)); // okay
std::format("{}", static_cast<const void*>(&d)); // okay
std::format("{}", nullptr); // okay
