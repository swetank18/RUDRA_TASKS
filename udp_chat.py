import socket
import threading
MY_IP   = "0.0.0.0"        
MY_PORT = 5006      
PEER_IP = "10.40.24.148"   
PEER_PORT = 5005


sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((MY_IP, MY_PORT))


has_token = False

def receive():
    global has_token
    while True:
        data, addr = sock.recvfrom(1024)
        msg = data.decode()

        if msg == "TOKEN":
            has_token = True
            print("\n--- You now have the token ---")
        else:
            print("\nPeer:", msg)

def sender():
    global has_token
    while True:
        if has_token:
            msg = input("You: ")
            if msg.strip() == "":
                continue

            sock.sendto(msg.encode(), (PEER_IP, PEER_PORT))

            
            sock.sendto(b"TOKEN", (PEER_IP, PEER_PORT))
            has_token = False


threading.Thread(target=receive, daemon=True).start()


sender()

