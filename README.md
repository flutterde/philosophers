# Philosophers

The Philosophers project is an implementation of the classic "Dining Philosophers" problem, a fundamental problem in concurrent programming. This project is part of the 42 coding school curriculum, aiming to teach students about synchronization, concurrency, and the challenges of avoiding deadlock and starvation in multithreaded applications.

In this project, a group of philosophers sit around a table with a fork between each pair of them. Each philosopher alternates between thinking and eating. However, a philosopher can only eat when they have both forks (one from the left and one from the right). The challenge is to design a solution that ensures no philosopher will starve while preventing any deadlock situations.

## How to use

To get started with the Philosophers project, follow these steps:

1. **Clone the Repository:**

   ```sh
   git clone https://github.com/flutterde/philosophers.git
   cd philosophers
   ```

2. **Build the Project:**

   This project uses `make` for building. Simply run:

   ```sh
   cd philo
   make
   ```

3. **Run the Simulation:**

   After building the project, you can run the simulation with:

   ```sh
   ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]
   ```

   - `number_of_philosophers`: The number of philosophers and also the number of forks.
   - `time_to_die`: Time in milliseconds before a philosopher dies if they haven't started eating.
   - `time_to_eat`: Time in milliseconds it takes for a philosopher to eat.
   - `time_to_sleep`: Time in milliseconds a philosopher spends sleeping.
   - `number_of_times_each_philosopher_must_eat`: (Optional) Number of times each philosopher must eat before the simulation ends. If not specified, the simulation will run indefinitely.

4. **Example:**

   ```sh
   ./philo 5 800 200 200
   ```

   This runs the simulation with 5 philosophers, each having 800ms to start eating before they die, taking 200ms to eat, and 200ms to sleep.

## Additional Information

This project is designed to help students understand the complexities of concurrent programming and develop strategies to manage multiple threads without running into issues like `deadlocks` and `race conditions`. It is an essential part of the curriculum at 42 coding school and provides practical experience with synchronization techniques.
