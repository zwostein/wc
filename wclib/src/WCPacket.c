#include <wc/WCPacket.h>

#include <string.h>


uint16_t WCPacket_size( WCPacket_Header * packet )
{
	return sizeof(WCPacket_Header) + (uint16_t)(packet->length);
}


void WCPacket_Message_create( WCPacket_Message * message, const char * text )
{
	message->header.type = WCPACKET_MESSAGE_TYPE;
	message->header.length = strlen(text) + 1;
	if( message->header.length > WCPACKET_MESSAGE_MAXLENGTH )
		message->header.length = WCPACKET_MESSAGE_MAXLENGTH;
	strncpy( message->text, text, message->header.length );
}


void WCPacket_Wheel_create( WCPacket_Wheel * wheel, uint8_t channel, uint8_t error, int16_t value )
{
	wheel->header.type = WCPACKET_WHEEL_TYPE;
	wheel->header.length = WCPACKET_WHEEL_LENGTH;
	wheel->channel = channel;
	wheel->error = error;
	wheel->value = value;
}
