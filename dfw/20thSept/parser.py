import argparse as agp
parser = agp.ArgumentParser(description= "A simple example of argparse")
parser.add_argument("name", type=str, help="Your name")
args = parser.parse_args()
print(f"Hello, {args.name}! ")
