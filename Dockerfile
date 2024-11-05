# Use an official Ubuntu as a parent image
FROM ubuntu:latest

# Set the working directory
WORKDIR /usr/src/app

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    libsfml-dev \
    make \
    g++

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Build the application
RUN make

# Run the application
CMD ["./snake_game"]