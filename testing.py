import os
import subprocess
import signal

config = {
    "server": True,
    "client": True
}

def run_command(command):
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, text=True)
    stdout, stderr = process.communicate()
    return process.returncode, stdout, stderr

print("Building the project in debug mode...")
build_command = "make debug"
return_code, stdout, stderr = run_command(build_command)

if return_code == 0:
    print("Build successful.")
else:
    print("Build failed. Exiting.")
    print("Stdout:", stdout)
    print("Stderr:", stderr)
    exit(1)

if config["server"]:
    server_command = "./server"
    print("Starting the server...")
    server_process = subprocess.Popen(server_command, preexec_fn=os.setpgrp, shell=True)

if config["client"]:
    num_clients = 20
    clients = []

    for i in range(num_clients):
        client_command = "./client"
        clients.append(subprocess.Popen(client_command, shell=True))

    print(f"Showing results for {num_clients} client instances...")

input("Press Enter to leave")

if config["client"]:
    for client in clients:
        client.terminate()

if config["server"]:
    os.killpg(os.getpgid(server_process.pid), signal.SIGTERM)

print("All clients and server have been stopped.")
