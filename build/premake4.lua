solution "Platformer"

	language "C++"
	location ( _ACTION )
	flags { "Symbols", "ExtraWarnings", "NoEditAndContinue", "NoPCH" }
	
	configurations { "Debug", "Release" }
	
	libdirs { "../lib" }
	
	-- Multithreaded compiling
	if _ACTION == "vs2010" or _ACTION == "vs2008" then
		buildoptions { "/MP" }
	end
	
	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" }
		includedirs { "../include/", "../src/" }
		objdir "../obj/Release"
		targetdir "../bin"
	
	configuration "Debug"
		defines { "_DEBUG" }
		includedirs { "../include/", "../src/" }
		objdir "../obj/Debug"
		targetdir "../debug"

	project "FlatWorld"
		uuid ( "937EEF0F-E3EE-460B-9311-544B11ECD2B8" )
		files { "../src/FlatWorld/**.*", "../include/*.**" }
		kind "StaticLib"

	project "Platformer"
		uuid ( "198F1F4A-B045-4D92-BB83-42D11E49EDA3" )
		files { "../src/Platformer/**.*", "../include/*.**" }
		kind "ConsoleApp"
		
		configuration "Release"
			links { "sfml-audio-s", "sfml-graphics-s", "sfml-network-s", "sfml-system-s", "sfml-window-s" }
		
		configuration "Debug"
			links { "sfml-audio-s-d", "sfml-graphics-s-d", "sfml-network-s-d", "sfml-system-s-d", "sfml-window-s-d" }

