# FILLER
Filler is an algorithmic game which consists in filling a grid of a known size in advance with pieces of random size and shapes, without the pieces being stacked more than one square above each other and without them exceeding the grid.
## Algorithm
	Heat map
## Bonus
Graphic visualizer written using a library `SDL2`

![Filler](https://github.com/fallard21/filler/blob/master/images/filler_gif.gif)

### How to use visualizer?
*Example:*
```
cd assets
./filler_vm -f maps/map01 -p1 ../fallard.filler -p2 ./champions/abanlin.filler | ../visualizer

or

./run.sh -g maps/map01 ../fallard.filler ./champions/abanlin.filler
```
Hold key `Arrow right` to play!

## How to download ?
	git clone https://github.com/fallard21/filler.git ~/filler
	cd ~/filler

## How to play ?
Install library's:
* `SDL2`
* `SDL2_ttf`
* `SDL2_image`
```
make -C .
cd assets
```
*Example:*
```
./filler_vm -f maps/map01 -p1 ../fallard.filler -p2 ./champions/abanlin.filler

or

./run.sh maps/map01 ../fallard.filler ./champions/abanlin.filler
```


## Supported OS
* Ubuntu
