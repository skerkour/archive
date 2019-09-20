FROM ubuntu

RUN apt-get update && apt-get install -y openssh-server && useradd skerkour -p skerkour
RUN mkdir /home/skerkour/
RUN mkdir /home/skerkour/.ssh


RUN sed -i 's/PermitRootLogin without-password/PermitRootLogin yes/' /etc/ssh/sshd_config

RUN sed -i 's/22/42/' /etc/ssh/sshd_config

ADD id_rsa.pub /home/skerkour/.ssh/authorized_keys

RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

ENV NOTVISIBLE "in users profile"

RUN echo "export VISIBLE=now" >> /etc/profile

EXPOSE 42

RUN /etc/init.d/ssh restart

CMD ["/usr/sbin/sshd", "-D"]
