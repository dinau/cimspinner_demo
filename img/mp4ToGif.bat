set name=cimspinner
ffmpeg -i %name%.mp4  -vf scale=480:-1   %name%.gif
