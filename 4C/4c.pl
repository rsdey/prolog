%RD zoo

% habitat
habitat(squirrel_monkey, tropical_forest).
habitat(polar_bear, polar).
habitat(ostrich, savanna).
habitat(ninja_turtle, city).

habitat(X, forest) :-
	X = grizzly_bear;
	X = swan;
	X = rattle_snake;
	X = long_nosed_monkey.

habitat(X, sea):-
	X = velvet_scoter;
	X = sea_turtle.

%temperature
temperature(X, warm_blooded):-
	bird(X);
	mammal(X).

temperature(X, cold_blooded):-
	reptile(X).


%mode of reproduction


reproduction(X, pregnancy):-
	mammal(X).

reproduction(X, egg):-
	bird(X);
	reptile(X).


%protection:
protection(X, fur):-
	mammal(X).

protection(X, feather):-
	bird(X).

protection(X, scale):-
	reptile(X).

%no. of legs:

leg(X, 2) :- bird(X);
	primate(X).

leg(X, 4) :-
	bear(X);
	turtle(X).

leg(snake, 0).


%types
flightless_land_bird(ostrich).
duck_like_bird(swan).
duck_like_bird(velvet_scoter).
primate(squirrel_monkey).
primate(long_nosed_monkey).
bear(grizzly_bear).
bear(polar_bear).
turtle(ninja_turtle).
turtle(sea_turtle).
snake(rattle_snake).

%categories:

bird(X):-
	flightless_land_bird(X);
	duck_like_bird(X).

mammal(X):-
	primate(X);
	bear(X).

reptile(X):-
	turtle(X);
	snake(X).

animal(X):-
	bird(X);
	mammal(X);
	reptile(X).

welcome(T):-
	write('Hello ! Welcome to the zoo :)'),write(T),nl,nl,
	write('Call the "animal" function to see the animals in the zoo.'),nl,
	write('Call the "details" function with animal name to explore . ').


details(X):-
	temperature(X,I),
	protection(X,N),
	leg(X, F),
	habitat(X, O),
	reproduction(X,G),

	write('Name: '), write(X),nl,
	write('Body Temperature: '), write(I),nl,
	write('protection:'), write(N),nl,
	write('Number of legs: '), write(F),nl,
	write('Natural Habitat: '), write(O),nl,
	write('Reproduction method: '), write(G).













