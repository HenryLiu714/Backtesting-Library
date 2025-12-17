# Base class for a strategy
class Strategy:
    def __init__(self):
        pass

    def on_bar(self, data):
        """Function called on every bar of data (OHLCV).

        Args:
            data (_type_): _description_

        Raises:
            NotImplementedError: _description_
        """
        raise NotImplementedError("handle_data method must be implemented by the strategy subclass.")