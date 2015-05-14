# 7 segment LED

First nice thing with the 7 segment LED (read [Wikipedia
article](https://duckduckgo.com/l/?kh=-1&uddg=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FSeven-segment_display)).

I have not used a driver to connect the LED to my arduino. Here's the
correspondence I've used:

| Arduino | LED |
| --- | --- |
|2    | 7 |
|3    | 6 |
|4    | 4 |
|5    | 2 |
|6    | 1 |
|7    | 9 |
|8    | 10 |
|9    | 5 |
|GND  | 3 & 8 |
| --- | --- |

By connecting this way, you'll notice that (see above's wikipedia
article) from 2 to 8 you'll readh A-G and 9 will control the dot.