import requests
import unittest

class CPPRESTAPITest(unittest.TestCase):
    def test_get(self):
        session = requests.Session()
        result = session.get(
            url = 'http://localhost:8080'
        )
        print(result)

if __name__ == "__main__":
    unittest.main(verbosity = 2)