solution "Platformer"

	language "C++"
	location ( _ACTION )
	flags { "Symbols", "ExtraWarnings", "NoEditAndContinue", "NoPCH" }
	
	configurations { "Debug", "Release" }
	
	includedirs { "../include" }
	libdirs { "../lib" }
	
	-- Multithreaded compiling
	if _ACTION == "vs2010" or _ACTION == "vs2008" then
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
		uuid ( "937EEF0F-E3EE-460B-9311-544B11ECD2B8" )
		includedirs { "../src/FlatWorld/" }
		files { "../src/FlatWorld/**.*" }
		kind "StaticLib"

	project "Platformer"
		uuid ( "198F1F4A-B045-4D92-BB83-42D11E49EDA3" )
		includedirs { "../src/Platformer/", "../src/", "../src/FlatWorld/" }
		files { "../src/Platformer/**.*" }
		kind "ConsoleApp"
		
		links { "gwen_static", "GWEN-Renderer-SFML", "FlatWorld" }
		if _ACTION == "vs2010" then
			links { "freetype2312", "ftgl_static", "glu32" }
			
			configuration "Release"
				links { "sfml-audio-s", "sfml-graphics-s", "sfml-network-s", "sfml-system-s", "sfml-window-s" }
			
			configuration "Debug"
				links { "sfml-audio-s-d", "sfml-graphics-s-d", "sfml-network-s-d", "sfml-system-s-d", "sfml-window-s-d" }
		else
			links { "freetype", "ftgl", "GLU" }
			
			configuration "Release"
				links { "sfml-audio", "sfml-graphics", "sfml-network", "sfml-system", "sfml-window" }
			
			configuration "Debug"
				links { "sfml-audio", "sfml-graphics", "sfml-network", "sfml-system", "sfml-window" }
		end

