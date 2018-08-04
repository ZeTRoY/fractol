<h1 align="center">Fract'ol</h1>
<h2 align="center">A 42 School Project</h2>

<h1 align="center">Description</h1>

<strong align="center">So what is this project about?</strong>  
<h2 align="center">What is a fractal?</h1>

	The term fractal was first used by mathematician Benoit Mandelbrot in 1974,
	he based it on the Latin word fractus, meaning "broken" or "fractured".
	A fractal is an abstract mathematical object, like a curve or a surface,
	which has a similar pattern whatever the scale.  

Here's an example of natural fractal - the romanesco cabbage:

![Picture](https://github.com/ZeTRoY/fractol/blob/master/Images/The_Romanesco_Cabbage.png?raw=true)

This project’s goal is to create a small fractal exploration program.  

To compile my project run:

	make

After that you should use: 

	./fractol

to see the command list. Also you can open up to three windows with different fractals!

My program can zoom in and zoom out with mouse scroll to/from your mouse point.
Zooming increases maximum quantity of iterations, also you can do it just by pressing '+' button.  

Here's what it looks like with:

	./fractol mandelbrot

![Picture](https://github.com/ZeTRoY/fractol/blob/master/Images/Mandelbrot_wasd.png?raw=true)

You can press 'H' to see different help options like:

	to move use 'W' 'A' 'S' and 'D'
	to increase/deacrease maximum quantity of iterations use '+'/'-'
	to use your mouse for changing fractal's form press 'Space'
		(the last one works only with Julia set)

You can change color palette by pressing apropriate button:

	'Z' for black'n'white color
	'X' for color with binary decomposition
	'C' for red color with gradient
	'V' for colorful representation of fractal
	'B' for psychodelic color or some sort of it :)
	'N' for red color width gradient (using logarithm formula)
	'M' for an interesting color palette (zoom in to see it better :) )

![Picture](https://github.com/ZeTRoY/fractol/blob/master/Images/Mandelbrot_colors.png?raw=true)

Also you can change fractals in your window by pressing:

	'1' for Mandelbrot

	'2' for Julia
	'3' for Mandelbar
	'4' for heart (I named it Heartbrot)
	'5' for Dualbrot
	'6' for so called "Great axe"
	'7' for Pentabrot
	'8' for Eggs (my own fractal, to see it, use 'V' or 'B' button)
	'9' for Burning ship
	'0' for Penta burning ship (named it Pentaburn)
	'1'(on keypad) for heart on Julia set
	'2'(on keyboard) for Pentajulia

![Picture](https://github.com/ZeTRoY/fractol/blob/master/Images/Mandelbrot_fractals.png?raw=true)

And mandelbrot fractal without help info is:

![Picture](https://github.com/ZeTRoY/fractol/blob/master/Images/Mandelbrot_w_o_help.png?raw=true)

To normalize your fractal use 'Backspace' button (resets to default settings).

Now here are some examples of my fractals:

![Picture](https://github.com/ZeTRoY/fractol/blob/master/Images/Julia.png?raw=true)
![Picture](https://github.com/ZeTRoY/fractol/blob/master/Images/Burning_ship.png?raw=true)
![Picture](https://github.com/ZeTRoY/fractol/blob/master/Images/Pentabrot_colorful.png?raw=true)