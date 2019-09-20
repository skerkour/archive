#ssh-keygen -C "skerkour" -t rsa

cp ~/.ssh/id_rsa.pub ./

cat id_rsa.pub > /Users/skerkour/.ssh/known_hosts

docker build -t ssh .
docker run -td -p 42 --name mission02 -h m02-sshd ssh
docker commit mission02 ssh

ssh skerkour@$(docker-machine ip) -p $(docker port mission02 42 | cut -d : -f 2)
