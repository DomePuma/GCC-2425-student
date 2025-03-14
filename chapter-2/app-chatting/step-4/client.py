#!/usr/bin/python3

import socket
import threading

SERVER_HOST = "172.31.17.141"
SERVER_PORT = 18080

MAX_BUFFER_SIZE = 1024

def receive_messages(client_socket):
    """Receive messages from client and display them."""
    while True:
        try:
            message = client_socket.recv(MAX_BUFFER_SIZE).decode("utf-8")
            if not message:
                break
            print(f"\n📩  # {message}")
            print(f"{client_socket.getsockname(())} > ", end='')
        except Exception as e:
            print(f"[Client] ❌ Connection closed. Error: {e}")
            break


def start_client():
    """Start client and handle message reception"""
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        client_socket.connect((SERVER_HOST, SERVER_PORT))

        print(f"[Client] ✅ Connected to server {SERVER_HOST}:{SERVER_PORT} from {client_socket.getsockname()}")

        receive_thread = threading.Thread(target=receive_messages, args=(client_socket,))
        receive_thread.daemon = True
        receive_thread.start()
        while True:
            message = input("> ")

            if message.lower() == "!quit" or message.lower() == "!q":
                print(f"\n[Client] 🛑 Disconnect client...")
                break

            client_socket.send(message.encode("utf-8"))
    except ConnectionRefusedError:
        print(f"[Client] ❌ Connection refused.")
    except KeyboardInterrupt:
        print(f"\n[Client] 🛑 Disconnect client...")
    finally:
        client_socket.close()
        print("[Client] ❌ Connection closed.")

if __name__ == "__main__":
    start_client()