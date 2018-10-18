#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
int main(){
    srand(time(0));
	//Resolusi
    RenderWindow app(VideoMode(800, 600), "Flappy Bird!");
    app.setFramerateLimit(60);

	//Texture
    Texture tBackground,tFloor,tBird;
    tBackground.loadFromFile("image/background.png");
    tFloor.loadFromFile("image/floor.png");
    tBird.loadFromFile("image/bird.png");
	Texture tBalokBawah,tBalokAtas;
	tBalokAtas.loadFromFile("image/pipe_top.png");
	tBalokBawah.loadFromFile("image/pipe_bot.png");
	Texture Menu;
	Menu.loadFromFile("image/startscreen.png");

	//Sprite
	Sprite sBackground(tBackground), sFloor(tFloor), sFloor2(tFloor), sPers(tBird);
	Sprite sBalokAtas[3],sBalokBawah[3];
	Sprite sBalokAtas2[3],sBalokBawah2[3];

	for(int a=0;a<3;a++){
	sBalokAtas[a].setTexture(tBalokAtas);
	sBalokBawah[a].setTexture(tBalokBawah);
	}

	for(int a=0;a<3;a++){
	sBalokAtas2[a].setTexture(tBalokAtas);
	sBalokBawah2[a].setTexture(tBalokBawah);
	}

 //koor. bird awal
  int x=200,y=200; 
 
 //koor. floor awal
 float xfloor2 = 800;
 float xfloor = 0, yfloor = 500;
 sFloor.setPosition(800,500); 
 sFloor2.setPosition(xfloor2, yfloor);
 
 //koor. pipe awal
 float xatas[3],yatas[3],xatas2[3],yatas2[3];
 float xbawah[3],ybawah[3],xbawah2[3],ybawah2[3];
 int piperand = rand()%270+50;
 yatas[0]= 0 - 1136 + piperand;
 ybawah[0]= piperand + 150;
 xatas[0]=800;
 xbawah[0]=800;

 piperand = rand()%270+50;
 yatas2[0] = 0 - 1136 + piperand;
 ybawah2[0] = piperand + 150;;
 xatas2[0]= 1200;
 xbawah2[0]= 1200;

 //pipe
 int flagspace = 0; 
 while (app.isOpen())
    {
        Event e;
		flagspace --;
        while (app.pollEvent(e))
        {
        if (e.type == Event::Closed){
		app.close();
   }
   if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Space)
   {
    if(flagspace <=0) {
     flagspace = 10;
    }
   }
   if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Space){
    flagspace = 0; 
   }
        }

  if(flagspace > 0)
  {
   y-=10;
  }
  else{
   y +=3;}
 

  // jatuh
  if(sPers.getPosition().y >= 450){
   break;
  }
  sPers.setPosition(x,y);

  //floor
  xfloor2-=5;xfloor-=5;
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

  //NABRAK
  // Atas
	if ((x+20)>=xatas[0]&&(x+20)<=xatas[0]+104){
	 if ((y) <=yatas[0]+1136 || (y) >= ybawah[0]){
		app.close();
	 }
 }

  //Kanan
 if((x+68)>=xatas[0]&&(x+68)<=xatas[0]+104){
   if((y+24)<=yatas[0]+1136 ||(y+24)>=ybawah[0]){
    app.close();
   }
 }

 if((x+65)>=xatas[0]&&(x+65)<=xatas[0]+104){
   if((y+5)<=yatas[0]+1136 ||(y+5)>=ybawah[0]){
    app.close();
   }
 }

 //bawah
  if ((x)>=xatas[0]&&(x)<=xatas[0]+104){
	 if ((y) <=yatas[0]+1136 || (y-15) >= ybawah[0]){
		app.close();
	 }
 }

  //kiri 
  if ((x+5)>=xatas[0]&&(x+5)<=xatas[0]+104){
	 if ((y+45) <=yatas[0]+1136 || (y+45) >= ybawah[0]){
		app.close();
	 }
 }

  // Atas
	if ((x+20)>=xatas2[0]&&(x+20)<=xatas2[0]+104){
	 if ((y) <=yatas2[0]+1136 || (y) >= ybawah2[0]){
		app.close();
	 }
 }

  //Kanan
 if((x+68)>=xatas2[0]&&(x+68)<=xatas2[0]+104){
   if((y+24)<=yatas2[0]+1136 ||(y+24)>=ybawah2[0]){
    app.close();
   }
 }

 if((x+65)>=xatas2[0]&&(x+65)<=xatas2[0]+104){
   if((y+5)<=yatas2[0]+1136 ||(y+5)>=ybawah2[0]){
    app.close();
   }
 }

 //bawah
  if ((x)>=xatas2[0]&&(x)<=xatas2[0]+104){
	 if ((y) <=yatas2[0]+1136 || (y-15) >= ybawah2[0]){
		app.close();
	 }
 }

  //kiri 
  if ((x+5)>=xatas2[0]&&(x+5)<=xatas2[0]+104){
	 if ((y+45) <=yatas2[0]+1136 || (y+45) >= ybawah2[0]){
		app.close();
	 }
 }

  //pipe
  xatas[0]-=5;
  xbawah[0]-=5;
  sBalokAtas[0].setPosition(xatas[0],yatas[0]);
  sBalokBawah[0].setPosition(xbawah[0],ybawah[0]);
  
  if(xatas[0]<=-104) //104
   {
    piperand=rand()%270+50;
    xatas[0]=800;
    yatas[0]=0-1136+piperand;
    xbawah[0]=800;
    ybawah[0]=piperand+150;
   }

  // pipe 2
  xatas2[0]-=5;
  xbawah2[0]-=5;
  sBalokAtas2[0].setPosition(xatas2[0],yatas2[0]);
  sBalokBawah2[0].setPosition(xbawah2[0],ybawah2[0]);
  
  if(xatas2[0]<= -104) //104
   {
    piperand=rand()%270+50;
    xatas2[0]=800;
    yatas2[0]=0-1136+piperand;
    xbawah2[0]=800;
    ybawah2[0]=piperand+150;
   }


  for(int a=0;a<3;a++){
   app.draw(sBalokAtas[a]);
   app.draw(sBalokBawah[a]);
  }

  app.draw(sBackground); 
  app.draw(sPers);
  app.draw(sBalokAtas[0]);
  app.draw(sBalokBawah[0]);
  app.draw(sBalokAtas2[0]);
  app.draw(sBalokBawah2[0]);
  app.draw(sFloor2);
  app.draw(sFloor);
  app.display();
 }
    return 0;
}