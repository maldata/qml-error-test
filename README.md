# QML Error Test

This application is intended to test an issue with QML applications.
When a loader's source is frequently changed, it eventually fails.
Other factors seem to affect this... for example, QML properties that
reference QObjects defined in Python, or the use of QML Shapes.

## Example Setup

- `c:\Python310\python.exe -m venv venv`
- `.\venv\Scripts\activate`
- `pip install -r .\requirements.txt`
- `python .\run-errortest.py`

It will then quickly cycle the loader between two QML sources until it
fails to load one. It will report the number of iterations until failure.
Comments in the code show where items can be changed or removed to change
the behavior.

## Results

| Python version | PySide6 version | Iterations to failure |
| -------------- | --------------- | --------------------- |
| 3.10.0         | 6.5.1           | 185                   |
| 3.10.0         | 6.2.1           | 161                   |
