docker run \
    -it \
    --rm \
    --mount type=bind,source=$(pwd),target=/code \
    --user $(id -u):$(id -g) \
    delay-plugin_compiler