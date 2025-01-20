# <p align="center">SOLONG [42 Project]</p>

<div align="center">
	<table>
		<tr><th>GRADE</th>
		<th>FRENCH VERSION</th></tr>
		<tr><th><img src="https://github.com/mgayout/mgayout/blob/main/img/note/125.png" height="100"></th>
		<th><a href= "https://github.com/mgayout/so_long"><img src="https://github.com/mgayout/mgayout/blob/main/img/french.png" height="100"></a></th></tr>
	</table>
</div>

The `SO_LONG` project is a 2D game, made with the `Minilibx` graphics library (provided by 42).

The goal of this game is to collect `items` on the `map` and take the `exit`.

Here are some examples of functionality requested by the subject of `SO_LONG`:

* Move in 4 directions (Up, Down, Left and Right)

* Show total trip count in terminal

* The `ESC` (or `ESC`) key allows you to properly exit the game

* The card played must contain at least 1 `entry` (starting position), 1 `exit` and an `item`

* ...

In addition to the use of a graphics library, the `SO_LONG` project allows us to understand the use of a structure and error handling.

### <p align="center">Bonus part</p>

The `bonus` part of this project includes the following 3 things:

* The player can lose the game if he is hit by an enemy

* The game must contain `sprite animations`

* The total movement count must be displayed directly in the game window

<p align="center"><img width="600" src="../clip/game.gif"></p>

## <p> </p>

## <p align="center">INSTALLATION</p>

* To download `SOLONG` :

```shell
git clone https://github.com/mgayout/so_long.git
```
<div align="center">
	<table>
		<tr><th colspan="2" align="center">Règles</th></tr>
		<tr><td align="center">make</td>
		<td>Compilation</td></tr>
		<tr><td align="center">make bonus</td>
		<td>Bonus files compilation</td></tr>
		<tr><td align="center">make clean</td>
		<td>Deleting object files</td></tr>
		<tr><td align="center">make fclean</td>
		<td>Deleting object files and the programm so_long or so_long_bonus</td></tr>
		<tr><td align="center">make re</td>
		<td>Deleting object files and the programm followed by compilation</td></tr>
		<tr><td align="center">make rebonus</td>
		<td>Deleting object files and the programm followed by bonus files compilation</td></tr>
	</table>
</div>

* To test `SOLONG` :

```shell
./so_long path/to/the/map.ber
```