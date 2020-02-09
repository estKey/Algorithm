# ! --* encoding: utf-8 *--
"""
Question:
Consider a single-server queue with geometrically distributed packet inter-arrival times and
service times as discussed in class, with a departure rate of µ = 0.8. Plot the expected queueing delay with respect to the arrival rate λ. Choose λ = [0.2, 0.4, 0.5, 0.6, 0.7, 0.75, 0.79, 0.795].
You should run the simulations for at least 106
time slots for each value of λ.
(Hints: use Little’s law to calculate the expected queueing delay, but you need to simulate
the queue dynamics to get the expected queue length first.)
"""
import matplotlib.pyplot as plt
from numpy import random


def bernoulli(_p):
    """
    Bernoulli Random Number Generator
    :param _p: the probability of
    :return: Bernoulli Random Number 0 or 1
    """
    return random.random() < _p  # return 0 if the random value is less than the probability


def single_server_queue(_t, _lambda, _mu):
    """

    :param _t: T, number of the trials to be executed
    :param _lambda: λ value of
    :param _mu:
    :return:
    """
    qk, queue_length = 0, 0
    for k in range(_t):
        ak = bernoulli(_lambda)
        if qk + ak > 0:
            dk = bernoulli(_mu)
        else:
            dk = 0
        qk = qk + ak - dk
        queue_length += qk
    return (queue_length / _t) / _lambda  # Return the


if __name__ == '__main__':
    print("Single Server Queue Simulation")
    _t = 10 ** 7
    _mu = 0.8
    _lambda = [0.2, 0.4, 0.5, 0.6, 0.7, 0.75, 0.79, 0.795]
    queuing_delay_list = []
    for _l in _lambda:  # iterates the lambda list to run all the simulation
        queuing_delay_list.append(single_server_queue(_t, _l, _mu))
    avg_queue_length = [x * y for x, y in zip(queuing_delay_list, _lambda)]
    print(f"Lambda: {_lambda}")
    print("Average Queue Length:", avg_queue_length)
    print(f"Average Queuing Delay: {queuing_delay_list}")
    plt.plot(_lambda, queuing_delay_list, label="expected queuing delay")
    plt.plot(_lambda, avg_queue_length, label="expected average queue length")
    font = {'family': 'Times New Roman',
            'weight': 'normal',
            'size': 15,
            }
    plt.xlabel("λ", font)
    plt.ylabel("Time Slot", font)
    plt.title('Single Server Queue Simulation', font)
    plt.legend()
    plt.show()
