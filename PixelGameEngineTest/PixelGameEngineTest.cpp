#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>

class Engine : public olc::PixelGameEngine
{
public:
    //Constructor
    Engine()
    {
        sAppName = "PixelGameEngine Test";
    }

	/// <summary>
	/// Called at the start of the engine and is made to setup initial
	/// settings and datafields for the engine
	/// </summary>
	/// <returns>Returns false if startup failed and engine must exit. True if startup was successful</returns>
	bool OnUserCreate() override
	{
		return true;
	}

	/// <summary>
	/// Code called every frame
	/// </summary>
	/// <param name="fElapsedTime">Time elapsed om seconds since last time this function was called</param>
	/// <returns>Returns false if engine is ready to exit. True if the engine should keep going</returns>
	bool OnUserUpdate(float fElapsedTime) override
	{
		//Create fuzz on the screen
		for (int x = 0; x < ScreenWidth(); x++)
		{
			for (int y = 0; y < ScreenHeight(); y++)
			{
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
			}
		}
			
		return true;
	}
};

int main()
{
    //Create engine
	Engine engineObject;

	//Startup the engine

	if (engineObject.Construct(1980/4, 1080/4, 4, 4))
	{
		engineObject.Start();
	}
}
