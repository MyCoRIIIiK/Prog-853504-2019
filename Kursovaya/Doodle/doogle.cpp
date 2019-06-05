#include <SFML/Graphics.hpp>       //сторонняя библотека 
#include <time.h>
#include <sstream>
#include <fstream>

using namespace sf;

int score = 0;
int Max = 0;

struct point
{ int x,y;};

void menu(RenderWindow & window) {
	std::ifstream Record("Score.txt");
	Record >> Max;

	Font font;                           //оформление шрифта
	font.loadFromFile("CyrilicOld.TTF");
	Text record("", font, 30);         

	record.setOutlineColor(Color::Black);   //параметры для записи текста рекорда
	record.setFillColor(Color::Black);
	record.setStyle(Text::Bold);
	
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;      //фон,картинки и т.д.
	menuTexture1.loadFromFile("111.png");	
	menuTexture3.loadFromFile("333.png");
	menuBackground.loadFromFile("background.png");
	Sprite menu1(menuTexture1),menu3(menuTexture3), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;

	std::ostringstream PlayerRecord;        //преобразование числа в string 

	PlayerRecord << Max;
	
	
	menu1.setPosition(100, 30);	
	menu3.setPosition(100, 150);
	menuBg.setPosition(0, 0);

	record.setString("Рекорд:"+PlayerRecord.str());
	record.setPosition(105, 75);
	Record.close();

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		Event e;
		while (window.pollEvent(e))    //чтобы можно было выйти из игры
		{
			if (e.type == Event::Closed)
				window.close();


		}
		menu1.setColor(Color::Black);
		
		menu3.setColor(Color::Black);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu3);
		window.draw(record);
		window.display();
	}
	////////////////////////////////////////////////////
}

int main()
{
	
	
    srand(time(0));

	Font font;
	font.loadFromFile("CyrilicOld.TTF");
	Text text("", font, 20), text2("", font, 30);
	text.setOutlineColor(Color::Black);
	text.setFillColor(Color::Black);
	text.setStyle(Text::Bold);

	text2.setOutlineColor(Color::Black);
	text2.setFillColor(Color::Black);
	text2.setStyle(Text::Bold);
	
begin:    RenderWindow app(VideoMode(400, 533), "Doodle Game!");
	menu(app);
	
    app.setFramerateLimit(60);

    Texture t1,t2,t3;
    t1.loadFromFile("fon.png");
    t2.loadFromFile("platform.png");
    t3.loadFromFile("doodle.png");

    Sprite sBackground(t1), sPlat(t2), sPers(t3);

    point plat[20];

    for (int i=0;i<10;i++)           //генерация места для плиток
      {
       plat[i].x=rand()%400;
       plat[i].y=rand()%533;
      }

	int x=100,y=100,h=200;
    float dx=0,dy=0;

    while (app.isOpen())
    {
		std::ofstream fScore("Score.txt");
        Event e;   
        while (app.pollEvent(e))    //чтобы можно было выйти из игры
        {
			if (e.type == Event::Closed)
                app.close();
			    
			
        }

    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=6;                  //взаимодействие с клавиатурой(стрелочки влево и вправо)
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=6;
	if (Keyboard::isKeyPressed(Keyboard::Up))
	if (Keyboard::isKeyPressed(Keyboard::Down)) app.setActive(true);


    dy+=0.2;   //скорость игры и высота прыжка
    y+=dy;
	if (y > 500)                  //если упал, конец игры
	{
		if (score > Max)
		{
			fScore << score;
			fScore.close();
		}		
		app.close();
		goto begin;       
		

	}
	if (x < 0) x = 400;         //если вышел за пределы карты, появляется в противоположной стороне
	if (x > 405) x = 0;          //х2
	score -= dy;               //подсчёт очков
	if (score < 0) score = 0;
	if (y<h)                   //перемещение экрана 
    for (int i=0;i<10;i++)
    {
      y=h;                           
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%400;}        //генерация платформ
    }

	for (int i = 0; i < 10; i++)           //перемещение дудла
	{
		if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
			&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0)) 
			  dy = -10;      //сила отталкивания от платформы
	}

	sPers.setPosition(x,y);

    app.draw(sBackground);
    app.draw(sPers);
    for (int i=0;i<10;i++)   //создание платформ
    {
    sPlat.setPosition(plat[i].x,plat[i].y);
    app.draw(sPlat);
    }
	std::ostringstream PlayerScore;   
	PlayerScore << score;   //заносим в переменную число очков
	text.setString("Очки:" + PlayerScore.str());   //задаем строку тексту и вызываем созданную строку методом .str()
	text.setPosition(20,20);     //позиция текста
	app.draw(text);   //рисование текста
    app.display();
}

	
    return 0;
}
