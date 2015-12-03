import time
import unittest

"""
We have n doors and n students to open it.
First student will open all the doors.
Second student will close all second doors.
Third student will goto every third door and toggle's the door.
This continues till n'th student.

Find the number of doors in open state after n'th student.
"""


def divisors(n):
    """
    Returns number of divisors given number 'n' has
    """
    return len(filter(lambda i: n % i == 0, range(1, n+1)))


def num_of_open_doors(n):
    """
    First student opens all the doors
    1 1 1 1 1 1 1...
    Second student closes every second doors
    1 0 1 0 1 0 1...
    Third student toggles every third doors
    1 0 0 0 0 0 1...
    Fourth student toggles every fourth doors
    1 0 0 1 0 0 1...

    As this continues we will have either odd or even number of toggles.
    Evenly toggled door will be closed where as oddly toggled door will be open.
    The solution is to find the number of odd divisors with in given n.
    """
    return len(filter(lambda i: i % 2 != 0, [divisors(x+1) for x in range(n)]))


def improvised(n):
    """
    Above solution works fine but it needs nested loop to do that.

    Instead we can calculate the square root of n.
    """
    return int(n ** 0.5)


class TestOpenDoors(unittest.TestCase):
    def setUp(self):
        self.start_time = time.time()

    def tearDown(self):
        t = time.time() - self.start_time
        print "%s: %.3f" % (self.id(), t)

    def test_divisor(self):
        self.assertEqual(num_of_open_doors(10000), 100)

    def test_sqrt(self):
        self.assertEqual(improvised(10000), 100)


if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestOpenDoors)
    unittest.TextTestRunner(verbosity=0).run(suite)
