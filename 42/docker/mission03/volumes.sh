docker build -t volumes .
docker run -v $(pwd):/test_mission03 -td -p 42 --name mission03 volumes
docker commit mission03 volumes

docker exec -it mission03 /bin/bash
