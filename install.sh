
#!/usr/bin/env sh

POPPER_VERSION="v2.7.0"

OS_NAME="$(uname)"
if [ "$OS_NAME" != "Linux" ] && [ "$OS_NAME" != "Darwin" ]; then
  echo "Popper only runs on Linux or MacOS. For Windows, we recommend WSL2."
  exit 1
fi

command -v docker >/dev/null 2>&1 || { echo >&2 "docker command not found. Aborting."; exit 1; }

cat > ./popper << "EOF"
#!/usr/bin/env sh
printenv > /tmp/.envfile
docker run --rm -ti \
  --volume /tmp:/tmp \
  --volume /var/run/docker.sock:/var/run/docker.sock \
  --volume $PWD:$PWD \
  --workdir $PWD \
  --env-file /tmp/.envfile \
  getpopper/popper:v2.7.0 $@
EOF

chmod +x "./popper"

echo "\nInstalled version $POPPER_VERSION to executable file $PWD/popper\n"

      if [ -d "/usr/local/bin" ]; then
        sudo -p "password: " -- mv ./popper /usr/local/bin/
      else
        sudo -p "password: " -- mkdir -p /usr/local/bin/
        sudo mv ./popper /usr/local/bin/
      fi
