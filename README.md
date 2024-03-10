<div align='center'>

# philosophers
#### _An introduction to the parallelisation paradigm_

[The project](#the-project) ~
[How to use it](#how-to-use-it) ~
[Interpreting the result](#interpreting-the-result)

</div>

## The project
This project explores the parallelisation paradigm through one of the most
famous computing problems: [the dining philosopher problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).

In this problem, an arbitrary number of philosophers (N) sit in a round table
for lunch with an arbitrary number of forks (also N). However, each philosopher
will need 2 forks to start eating leaving N / 2 philosophers without
the possibility of eating.

From this moment, the philosophers will need to eat, sleep, and of course think
time after time in an infinite loop that will only end if one of them starves
as a result of other philosophers eating for too long (or not respecting each
other's times).

Finally, the problem has a small detail that makes things even more complicated:
an odd and an even number of philosophers will have different behaviours!

As mentioned before, up to N / 2 philosophers can eat simulaneously. When an odd
number of philosophers sit, there will be one of them with the possibility of
immediately taking a fork! Coordinating everyone else around him to respect his
moment will be critical as the other philosophers may end up in a lethal position
(deadlock) if the philosopher with the one fork doesn't eat as soon as possible.

## How to use it
A simple `make` should be enough to get a file `./philo` which can be executed
with the following parameters:

```bash
./philo <number of philosophers> <time to starve> <time eating> <time sleeping> [max iterations]
```

## Interpreting the result
The following call will produce a simple output that we can easily understand:

```bash
$ ./philo 3 100 50 50
0 1 has taken a fork
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
50 3 is sleeping
50 1 has taken a fork
50 1 is eating
100 3 is thinking
100 2 has taken a fork
100 2 has taken a fork
100 3 has taken a fork
100 1 is sleeping
100 2 is eating
110 3 died
```

3 philosophers sit at a table. If they don't eat every 100 milliseconds, they
die. Each of them will take 50 milliseconds to eat, and will spend 50 sleeping.

Philosopher n1 takes a fork, but before he can take the second one n3 takes
two forks and starts eating. 50ms later, he starts sleeping as he finishes eating
and n1 can take the second fork (_if n2 had taken the other fork, a deadlock
would have killed both of them_). n1 eats and goes to sleep, but by the time n2
finishes eating n3 doesn't have enough time and starves to death.
