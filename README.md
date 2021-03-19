# canvas-drawer

Implements a simple drawing api


![kitten](https://user-images.githubusercontent.com/55757317/111721123-a9e60380-8835-11eb-8aab-16636a07557f.png)


## How to build

*Windows*

Open git bash to the directory containing this repository.

```
canvas-drawer $ mkdir build
canvas-drawer $ cd build
canvas-drawer/build $ cmake -G "Visual Studio 16 2019" ..
canvas-drawer/build $ start Draw-2D.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
canvas-drawer/build $ ../bin/Debug/draw_test
canvas-drawer/build $ ../bin/Debug/draw_art
```

*macOS*

Open terminal to the directory containing this repository.

```
canvas-drawer $ mkdir build
canvas-drawer $ cd build
canvas-drawer/build $ cmake ..
canvas-drawer/build $ make
```

To run each program from build, you would type

```
canvas-drawer/build $ ../bin/draw_test
canvas-drawer/build $ ../bin/draw_art
```

## Supported primitives

LINES

![horizontal-line](https://user-images.githubusercontent.com/55757317/111714345-d2ff9780-8827-11eb-9bc4-c685e3a8947f.png) ![vertical-line](https://user-images.githubusercontent.com/55757317/111714359-d7c44b80-8827-11eb-91eb-7f45533288c9.png) ![diagonal-line-1](https://user-images.githubusercontent.com/55757317/111714369-dbf06900-8827-11eb-9566-ce8613252e59.png) ![h-lessthan-w-line-1](https://user-images.githubusercontent.com/55757317/111714382-e3177700-8827-11eb-8f01-a8af2f8832a5.png) ![w-lessthan-h-line-1](https://user-images.githubusercontent.com/55757317/111714386-e9a5ee80-8827-11eb-84e2-b765edcf16b5.png) ![diagonal-line-2](https://user-images.githubusercontent.com/55757317/111714399-f0ccfc80-8827-11eb-8936-289ce6a09197.png) ![h-lessthan-w-line-2](https://user-images.githubusercontent.com/55757317/111714416-f9bdce00-8827-11eb-9bf6-f1530a0e2607.png) ![w-lessthan-h-line-2](https://user-images.githubusercontent.com/55757317/111714425-fcb8be80-8827-11eb-84bc-6d0fe70201ac.png)

LINES with interpolation

![line-color-interpolation](https://user-images.githubusercontent.com/55757317/111714944-2aeace00-8829-11eb-8ba4-ffc810c5b62e.png)

TRIANGLES
outlined/filled/with interpolation/2 triangles


![triangle-outlined](https://user-images.githubusercontent.com/55757317/111715487-499d9480-882a-11eb-9134-f39db15ff681.png) ![triangle-filled](https://user-images.githubusercontent.com/55757317/111715495-4c988500-882a-11eb-86c5-f2f8ead5e260.png) ![triangle](https://user-images.githubusercontent.com/55757317/111715542-6e920780-882a-11eb-8e48-b7cced73d299.png) ![quad](https://user-images.githubusercontent.com/55757317/111716316-21af3080-882c-11eb-9577-254a2a489c76.png)

CIRCLES
outlined/filled/gradient

![circleOutline](https://user-images.githubusercontent.com/55757317/111715989-73a38680-882b-11eb-8f0b-1f1d306b4c28.png) ![circleFilled](https://user-images.githubusercontent.com/55757317/111715992-7605e080-882b-11eb-9261-71ff342ed4ce.png) ![circleGradient](https://user-images.githubusercontent.com/55757317/111715994-7900d100-882b-11eb-9346-3fddf9cca8c6.png)

RECTANGLES

oulined/fileld

![rectangleOutlined](https://user-images.githubusercontent.com/55757317/111716466-7b175f80-882c-11eb-9d65-f181c20cf85a.png) ![rectangleFilled](https://user-images.githubusercontent.com/55757317/111716471-7e125000-882c-11eb-8ef8-68121296b3ed.png)

## Results

![owl](https://user-images.githubusercontent.com/55757317/111714170-79976880-8827-11eb-85b6-61d9dacf5a3e.png)
