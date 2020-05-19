# coding: utf-8

from __future__ import absolute_import

from flask import json
from six import BytesIO

from swagger_server.test import BaseTestCase


class TestLightColorController(BaseTestCase):
    """LightColorController integration test stubs"""

    def test_root(self):
        """Test case for root

        help
        """
        response = self.client.open(
            '/',
            method='GET')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_switch_light_color(self):
        """Test case for switch_light_color

        switch light color
        """
        response = self.client.open(
            '/light/{color}'.format(color='color_example'),
            method='PUT')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))


if __name__ == '__main__':
    import unittest
    unittest.main()
