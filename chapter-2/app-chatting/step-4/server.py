#!/usr/bin/python3

import socket
import threading

SERVER_HOST = "127.0.0.1"
SERVER_PORT = 18080
MAX_BUFFER_SIZE = 1024

clients = []
clients_lock = threading.Lock() # lock to protect concurrent access

def broadcast(message, sender_socket):
    with clients_lock:
        for client in clients:
            if client != sender_socket:
                try:
                    client.send(message.encode("utf8"))
                except:
                    print(f"[Server] {client} has disconnected")
                    clients.remove(client)
                    client.close()


def handle_client(client_socket, client_address):
    """Handle the communication with a specific client"""
    print(f"[Client] ✅ {client_address} connected.")

    with clients_lock:
        clients.append(client_socket)

    try:
        while True:
            message = client_socket.recv(MAX_BUFFER_SIZE).decode("utf-8")
            if not message:
                break
            print(f"[Client {client_address}] {message}")

            broadcast(f"<{client_address}> {message}", client_socket)

    except ConnectionResetError:
        print(f"[Server] ⚠️ Connection reset by peer {client_address}")
    except Exception as e:
        print(f"[Server] ⚠️ Error with client {client_address}: {e}")
    finally:
        print(f"[Server] ❌ Closing connection {client_address}")
        with clients_lock:
            clients.remove(client_socket)
        client_socket.close()

def start_server():
    """Start the TCP server and accept connections."""
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((SERVER_HOST, SERVER_PORT))
    server_socket.listen()

    print(f"[Server] 🚀 Start listening on  {SERVER_HOST}:{SERVER_PORT}...")
    try:
        while True:
            client_socket, client_address = server_socket.accept()

            client_thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
            client_thread.start()
    except KeyboardInterrupt:
        print(f"\n[Server] 🛑 Shutdown server...")

    finally:
        for client in clients:
            client.close()
        server_socket.close()
        print("[Server] ✅ Shutdown complete.")


if __name__ == "__main__":
    start_server()