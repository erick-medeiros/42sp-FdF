FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    xorg \
    make \
    gcc \
    build-essential \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    && rm -rf /var/lib/apt/lists/*

# WORKDIR /src

# COPY . .

# RUN cd /src/lib/libft && make

# RUN cd /src/lib/mlx_linux && chmod +x configure && make

# RUN cd /src && make

CMD [ "bash" ]