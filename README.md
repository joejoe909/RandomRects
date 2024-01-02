# Random Rectangles 
#### This Qt Widgets Project uses the C++ random library to generate random rectangles within a Qt Widgets MainWindow. Users can regenerate them simply by clicking within the window or resizing. 

#### Thus, you experience pleasing output as such: 
<img src="Repo Screenshot.png">

#### The number of rectangles drawn can be adjusted by changing the for loop in the paintEvent function. The geometry of the rectangles and color range can also be adjusted here. 
``` C++
void MainWindow::paintEvent(QPaintEvent *event)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rnd_color(0, 255);
    std::uniform_int_distribution<int> rnd_x(0, 1920);
    std::uniform_int_distribution<int> rnd_y(0, 1080);
    std::uniform_int_distribution<int> rnd_w(0, 500);
    std::uniform_int_distribution<int> rnd_h(0, 200);

    for(int i = 0; i < 1200; ++i)
    {
        QPainter painter(this);
        painter.setPen(QColor(rnd_color(gen), rnd_color(gen), rnd_color(gen), 255));
        painter.drawRoundedRect(QRect(rnd_x(gen),rnd_y(gen),rnd_w(gen),rnd_h(gen)), 0.0, 0.0, Qt::AbsoluteSize);
    }
}

```