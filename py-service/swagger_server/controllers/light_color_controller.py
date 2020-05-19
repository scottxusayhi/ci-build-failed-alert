import connexion
import six

from swagger_server import util
from control import get_light, default_light

light = get_light(default_light)


def root():  # noqa: E501
    """help

     # noqa: E501


    :rtype: None
    """
    return {
        "summary": "control the light colors",
        "links": [
            {"name": "turn off", "type": "GET", "url": "/light/off"},
            {"name": "turn red", "type": "GET", "url": "/light/red"},
            {"name": "turn orange", "type": "GET", "url": "/light/orange"},
            {
                "name": "turn yellow green (2)",
                "type": "GET",
                "url": "/light/yellow_green_2",
            },
            {"name": "turn yellow green", "type": "GET", "url": "/light/yellow_green"},
            {"name": "turn light green", "type": "GET", "url": "/light/light_green"},
            {"name": "turn green", "type": "GET", "url": "/light/green"},
        ],
    }


def switch_light_color(color):  # noqa: E501
    """switch light color

     # noqa: E501

    :param color: 
    :type color: str

    :rtype: None
    """
    return {"code": 0, "message": light.switch(color).decode()}
