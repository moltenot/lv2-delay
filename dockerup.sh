docker run \
    -it \
    --rm \
    --mount type=bind,source=$(pwd),target=/code \
    delay-plugin_compiler