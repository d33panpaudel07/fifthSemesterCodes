def prepare_message(user_message):
    # This is easier to understand
    user_message = user_message.replace(" ", "")
    user_message = user_message.replace("j", "i")
    user_message = user_message.upper()

    # ONLY AN IDIOT PREFERS COMPLEXITY AND TIME CONSUMPTION UNLESS HE'S DONE CODE LIKE BELOW ,BEFOREHAND
    # user_message = user_message.replace(" ", "").replace("j", "i").upper()

    return user_message


def make_pairs_of_message(user_message):
    user_message_in_pairs = []
    lead_char_from_pair = 0
    i = 2
    while i <= len(user_message):
        # for i in range(2, len(user_message), 2):
        if user_message[lead_char_from_pair] == user_message[lead_char_from_pair + 1]:
            user_message_in_pairs.append(user_message[lead_char_from_pair] + "X")
            lead_char_from_pair = i - 1
            i = i + 1
            continue
        # TAKING PAIRS FROM STRING AS LEAD CHARACTER IS 0 INITIALLY AND I IS 2 SO IN A STRING "HELLO" LEAD INDEXES H I INDEXES L AND CODE BELOW APPENDS TO A LIST FROM LEAD(INCLUSIVE) TO I(EXCLUSIVE) e_in_pairs = user_message_in_pairs.append( user_messa
        user_message_in_pairs.append(user_message[lead_char_from_pair:i])
        # UPDATING LEAD TO I AS I WILL BE INCREMENTED IN LOOP DECLARATION BY 2
        lead_char_from_pair = i
        i = i + 2
    # THIS IS TO PUT REMAININ LAST PAIR IN THE LIST AS WELL BECAUSE THE LOOP STOPPED WHEN I = LAST LENGTH
    user_message_in_pairs.append(user_message[lead_char_from_pair:])
    if len(user_message_in_pairs[-1]) != 2:
        user_message_in_pairs[-1] += "Z"

    return user_message_in_pairs


def main():
    user_message = "HElloooooo"
    # user_message = input("Enter a message: ")
    # user_key = input("Enter a key: ")
    # user_operation = input("Enter 1 to encrypt or 2 to decrypt: ")
    user_message = prepare_message(user_message)
    print(user_message)
    user_message = make_pairs_of_message(user_message)
    print(user_message)
