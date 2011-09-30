solution "Platformer"

	language "C++"
	location ( _ACTION )
	flags { "Symbols", "ExtraWarnings", "NoEditAndContinue", "NoPCH" }
	defines { "SFML_STATIC" }
	
	configurations { "Debug", "Release" }
	
	includedirs { "../include" }
	libdirs { "../lib" }
	
	-- Multithreaded compiling
	vs = _ACTION == "vs2010" or _ACTION == "vs2008"
	if vs then
		buildoptions { "/MP" }
		linkoptions { "/nodefaultlib:libcmt" } -- fixes a warning
	end
	
	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" }
		objdir "../obj/"
		targetdir "../bin"
	
	configuration "Debug"
		defines { "_DEBUG" }
		objdir "../obj/"
		targetdir "../debug"

	project "FlatWorld"
		if vs then
			location "../src/FlatWorld/"
		end
		uuid ( "937EEF0F-E3EE-460B-9311-544B11ECD2B8" )
		includedirs { "../src/FlatWorld/" }
		files { "../src/FlatWorld/**.h", "../src/FlatWorld/**.cpp" }
		kind "StaticLib"

	project "Platformer"
		if vs then
			location "../src/Platformer/"
		end
		uuid ( "198F1F4A-B045-4D92-BB83-42D11E49EDA3" )
		includedirs { "../src/Platformer/", "../src/", "../src/FlatWorld/" }
		files { "../src/Platformer/**.h", "../src/Platformer/**.cpp" }
		kind "ConsoleApp"
		
		links { "gwen_static", "GWEN-Renderer-SFML", "FlatWorld" }
		if vs then
			links { "freetype2312", "glu32" }
			
			configuration "Release"
				links { "ftgl_static" }
				links { "sfml-audio-s", "sfml-graphics-s", "sfml-network-s", "sfml-system-s", "sfml-window-s" }
			
			configuration "Debug"
				links { "ftgl_static_d" }
				links { "sfml-audio-s-d", "sfml-graphics-s-d", "sfml-network-s-d", "sfml-system-s-d", "sfml-window-s-d" }
		else
			links { "freetype", "ftgl", "GLU" }
			
			configuration "Release"
				links { "sfml-audio", "sfml-graphics", "sfml-network", "sfml-system", "sfml-window" }
			
			configuration "Debug"
				links { "sfml-audio", "sfml-graphics", "sfml-network", "sfml-system", "sfml-window" }
		end
