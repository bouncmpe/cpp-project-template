# Follow commands below to build and run the container
#
# > docker build . -t bouncmpe/cpp_project_template:latest
# > docker run -it --rm -v $(PWD):/workspaces/bouncmpe bouncmpe/cpp_project_template

FROM ubuntu:22.04

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install \
        sudo \
        git \
        build-essential \
        tar curl wget zip unzip gnupg2 \
        cmake \
        ninja-build \
        python3-all-dev \
        python3-pip \
        python-is-python3 \
    && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*
   
RUN git clone -j$(nproc) --recursive --depth 1 --branch boost-1.81.0 https://github.com/boostorg/boost.git /tmp/boost \
    && cd /tmp/boost \
    && ./bootstrap.sh --prefix=/usr/local --without-libraries=python \
    && ./b2 -j$(nproc) install \
    && cd / && rm -rf /tmp/boost

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install \
        clang \
        clang-format \
        clang-tidy \
        clang-tools \
    && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*

RUN git clone --depth 1 --branch v3.2.2 https://github.com/catchorg/Catch2.git /tmp/catch2 \
    && cmake -S/tmp/catch2 -B/tmp/catch2/build \
    -DBUILD_TESTING=OFF \
    -DCATCH_INSTALL_DOCS=OFF \
    && cmake --build /tmp/catch2/build/ --target install -j$(nproc) \
    && rm -rf /tmp/catch2

# Add a container user (good practice)
RUN groupadd work -g 1000 \
   && useradd -ms /bin/bash bouncmpe -g 1000 -u 1000 \
   && printf "bouncmpe:bouncmpe" | chpasswd \
   && printf "bouncmpe ALL= NOPASSWD: ALL\\n" >> /etc/sudoers

USER bouncmpe

RUN python -m pip install --user \
  gcovr \
  pre-commit \
  cmakelang[YAML]

ENV PATH "/home/bouncmpe/.local/bin:${PATH}"