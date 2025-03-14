import socket
import threading

SERVER_HOST = "127.0.0.1"
SERVER_PORT = 18080
MAX_BUFFER_SIZE = 1024

def receive_message(client_socket):
    """Receive message from client and display them"""
    while True:
        try:
            message = client_socket.recv(MAX_BUFFER_SIZE).decode("utf-8")
            if not message:
                break
            print(f"\n {message}")
        except Exception as e:
            print(f"[Client] Connection closed. Error {e}")

def start_client():
    """Start client and handle message reception"""
    try:
        client_socket = socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((SERVER_HOST, SERVER_PORT))
        print(f"[Client] Connected to server {SERVER_HOST}:{SERVER_PORT}")

        receive_thread = threading.Thread(target=receive_message, args=(client_socket))
        receive_thread.deamon = True
        receive_thread.start()

        while True :
            message = input("> ")

            if message.lower() == "!quit" or message.lower() == "!q":
                break

            client_socket.send(message.encode("utf-8"));

    except KeyboardInterrupt:
        print(f"[Client] Closing client")

    finally :
        client_socket.close()
        print("Connection closed.")

if __name__ == "__main__" :
    start_client()