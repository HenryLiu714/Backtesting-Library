from Backtester import Engine


configs = {"Hello": 123}
e = Engine(configs)
value = e.get_config("Hello")
print(f"Config 'Hello' has value: {value}")


