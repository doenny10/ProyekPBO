#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;
struct point
{ int x,y;};
int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(500, 600), "Flappy Bird!");
    app.setFramerateLimit(80);

    Texture t1,t2,t3, t4 ;
    t1.loadFromFile("image/background.png");
    t2.loadFromFile("image/floor.png");
	t4.loadFromFile("image/floor.png");
    t3.loadFromFile("image/bird.png");
	
	Texture balokbawah,balokatas;
	balokatas.loadFromFile("image/pipe_top.png");
	balokbawah.loadFromFile("image/pipe_bot.png");

    Sprite sBackground(t1), sFloor(t2), sFloor2(t4), sPers(t3);
	Sprite sBalokAtas(balokatas), sBalokBawah(balokbawah);
	Sprite sBalokAtas2(balokatas), sBalokBawah2(balokbawah);

	//koor. awal burung
	int x=200,y=200;
    int dx=0,dy=0;
	
	//koor. awal floor
	int xfloor2 = 800;
	int xfloor = 0, yfloor = 500;
	sFloor.setPosition(800,500); 
	sFloor2.setPosition(xfloor2, yfloor);
	
	//koor. pipe awal
	int ran = rand()%200 + 50;
	int	ybaloka = -1100 + ran;
	int xbalok = 500; //800
	int xbalok2 = 500; //800
	cout<<ybaloka;
	while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

    if (Keyboard::isKeyPressed(Keyboard:: Space)) y-=5;
	else{
		y += 5;
	}

	// jatuh
	if(sPers.getPosition().y >= 450){
		break;
	}
	sPers.setPosition(x,y);

	//floor
	xfloor2-=2;xfloor-=2;
	sFloor.setPosition(xfloor,yfloor);
	sFloor2.setPosition(xfloor2, yfloor);
	if(xfloor <= -800){
		xfloor=800;
		sFloor.setPosition(xfloor,yfloor);
	}
	if(xfloor2<=-800){
		xfloor2=800;
		sFloor2.setPosition(xfloor2, yfloor);
	}

	//pipe
	if(xbalok >= -100){ 
	sBalokAtas.setPosition(xbalok-=2,ybaloka);
	sBalokBawah.setPosition(xbalok-=2,ybaloka + 1300);	
	xbalok2 = 500; //800
	}
	else if(xbalok2 >= -100){
	sBalokAtas.setPosition(xbalok2-=2,ybaloka);
	sBalokBawah.setPosition(xbalok2-=2,ybaloka + 300);
	xbalok = 500; //800	
	}

	//random pipe
	if(xbalok <= -100){ 
		ran = rand()%200 + 50;
		ybaloka = -1100 + ran;
		xbalok = 500; //800
	}

	int kond = sBalokAtas.getPosition().y + (ybaloka * -1);
	if(sPers.getPosition().y <= kond && sPers.getPosition().x == xbalok){
		break;
	}

	cout<<ran<<endl;
	cout<<sPers.getPosition().y<<endl<<"   "<<sBalokAtas.getPosition().y + (ybaloka * -1);
	
	app.draw(sBackground); 
	app.draw(sBalokAtas);
	app.draw(sBalokBawah);
	app.draw(sFloor2);
	app.draw(sFloor);
	app.draw(sPers);
    app.display();
	}
    return 0;
}
