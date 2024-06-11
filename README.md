# Cub3D

# Some Tips of how to get the Project done
- https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf
- https://reactive.so/post/42-a-comprehensive-guide-to-cub3d

# MLX42 download (will make something in makefile to download automatically)
```
git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build # build here refers to the outputfolder.
cmake --build build -j4 # or do make -C build -j4
```

# Raycasting steps (simplified):
1. Get the exact position of the player inside of the tille he is standing
2. Get the rest of the lenght until collision with a wall
3. Repeat until the FOV was covert
