import time
import unittest


def xo(s):
    s = s.upper()
    return s.count('X') == s.count('O')


class TestExesOhs(unittest.TestCase):
    def setUp(self):
        self.start_time = time.time()

    def tearDown(self):
        t = time.time() - self.start_time
        print '%s: %.3f' % (self.id(), t)

    def test_simple(self):
        self.assertEqual(xo('xxoo'), True)

    def test_complex(self):
        self.assertEqual(xo('xadfjakjozxkxciojojlx'), False)


if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestExesOhs)
    unittest.TextTestRunner(verbosity=0).run(suite)
